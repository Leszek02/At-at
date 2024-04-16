#include <headers.h>

//Procedura obsługi błędów
void error_callback(int error, const char* description) {
	fputs(description, stderr);
}

GLuint readTexture(const char* filename, int texturingUnit) {
	GLuint tex;
	glActiveTexture(texturingUnit);

	//Wczytanie do pamięci komputera
	std::vector<unsigned char> image;   //Alokuj wektor do wczytania obrazka
	unsigned width, height;   //Zmienne do których wczytamy wymiary obrazka
	//Wczytaj obrazek
	unsigned error = lodepng::decode(image, width, height, filename);

	//Import do pamięci karty graficznej
	glGenTextures(1, &tex); //Zainicjuj jeden uchwyt
	glBindTexture(GL_TEXTURE_2D, tex); //Uaktywnij uchwyt
	//Wczytaj obrazek do pamięci KG skojarzonej z uchwytem
	glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, (unsigned char*)image.data());
	glGenerateMipmap(GL_TEXTURE_2D); // działa
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // Dla ubogich - overrided by MipMap
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_MIRRORED_REPEAT); // powtarzanie tekstury - odbite
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR); //MimMap
	//glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAX_ANISOTROPY_EXT, 16.0f); // Filtrowanie antyizotropowe - overriduje MipMapę

	return tex;
}

GLuint loadSkybox() {
	GLuint tex;
	glActiveTexture(GL_TEXTURE0);

	//Wczytanie do pamięci komputera
	std::vector<unsigned char> image;   //Alokuj wektor do wczytania obrazka
	unsigned width, height;   //Zmienne do których wczytamy wymiary obrazka
	//Wczytaj obrazek
	

	//Import do pamięci karty graficznej
	glGenTextures(1, &tex); //Zainicjuj jeden uchwyt
	glBindTexture(GL_TEXTURE_CUBE_MAP, tex); //Uaktywnij uchwyt
	//Wczytaj obrazek do pamięci KG skojarzonej z uchwytem
	unsigned error = lodepng::decode(image, width, height, "textures/Skybox/skybox_right.png");
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, 4, width, height, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, (unsigned char*)image.data());
	image.clear();
	error = lodepng::decode(image, width, height, "textures/Skybox/skybox_left.png");
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, 4, width, height, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, (unsigned char*)image.data());
	image.clear();
	error = lodepng::decode(image, width, height, "textures/Skybox/skybox_top.png");
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, 4, width, height, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, (unsigned char*)image.data());
	image.clear();
	error = lodepng::decode(image, width, height, "textures/Skybox/skybox_bottom.png");
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, 4, width, height, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, (unsigned char*)image.data());
	image.clear();
	error = lodepng::decode(image, width, height, "textures/Skybox/skybox_back.png");
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, 4, width, height, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, (unsigned char*)image.data());
	image.clear();
	error = lodepng::decode(image, width, height, "textures/Skybox/skybox_front.png");
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, 4, width, height, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, (unsigned char*)image.data());

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	return tex;
}

//Procedura inicjująca
Model initOpenGLProgram(GLFWwindow* window, Model atat) {
	glClearColor(0.596, 0.012, 0.631, 1);
	initShaders();
	glEnable(GL_DEPTH_TEST);
	//glDisable(GL_CULL_FACE); nope
	glfwSetKeyCallback(window, key_callback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(window, cameraRotation);
	tex0 = readTexture("textures/atat_diffuse.png", GL_TEXTURE0); //TEKSTURY MUSZĄ BYĆ ROZMIARU 1024X1024, INACZEJ NIE ZADZIAŁA (i chyba też musi byc png)
	tex0spec = readTexture("textures/atat_spectral.png", GL_TEXTURE1);
	tex1 = readTexture("textures/Floor/render_map.png", GL_TEXTURE0);
	atat.loadModel(std::string("models/atat.obj"));
	tex2 = loadSkybox();
	//gluPerspective(45.0f, 16 / 9, 0.1, 10000.0f);
	return atat;
}


//Zwolnienie zasobów zajętych przez program
void freeOpenGLProgram(GLFWwindow* window) {
    freeShaders();
	glDeleteTextures(1, &tex0);
	glDeleteTextures(1, &tex0spec);
	glDeleteTextures(1, &tex1);
	glDeleteTextures(1, &tex2);
    //************Tutaj umieszczaj kod, który należy wykonać po zakończeniu pętli głównej************
}

void texKostka(glm::mat4 P, glm::mat4 V, glm::mat4 M) { //Na razie ją zostawiłem, testuje na niej rzeczy

	float myCubeTexCoords[] = {
		1.0f, 0.0f,	  0.0f, 1.0f,    0.0f, 0.0f,
		1.0f, 0.0f,   1.0f, 1.0f,    0.0f, 1.0f,

		1.0f, 0.0f,	  0.0f, 1.0f,    0.0f, 0.0f,
		1.0f, 0.0f,   1.0f, 1.0f,    0.0f, 1.0f,

		1.0f, 0.0f,	  0.0f, 1.0f,    0.0f, 0.0f,
		1.0f, 0.0f,   1.0f, 1.0f,    0.0f, 1.0f,

		1.0f, 0.0f,	  0.0f, 1.0f,    0.0f, 0.0f,
		1.0f, 0.0f,   1.0f, 1.0f,    0.0f, 1.0f,

		1.0f, 0.0f,	  0.0f, 1.0f,    0.0f, 0.0f,
		1.0f, 0.0f,   1.0f, 1.0f,    0.0f, 1.0f,

		1.0f, 0.0f,	  0.0f, 1.0f,    0.0f, 0.0f,
		1.0f, 0.0f,   1.0f, 1.0f,    0.0f, 1.0f,
	};

	spCustom->use(); //Aktywuj program cieniujący

	glUniformMatrix4fv(spCustom->u("P"), 1, false, glm::value_ptr(P)); //Załaduj do programu cieniującego macierz rzutowania
	glUniformMatrix4fv(spCustom->u("V"), 1, false, glm::value_ptr(V)); //Załaduj do programu cieniującego macierz widoku
	glUniformMatrix4fv(spCustom->u("M"), 1, false, glm::value_ptr(M)); //Załaduj do programu cieniującego macierz modelu


	glEnableVertexAttribArray(spCustom->a("vertex"));
	glVertexAttribPointer(spCustom->a("vertex"), 4, GL_FLOAT, false, 0, myCubeVertices); //Współrzędne wierzchołków bierz z tablicy myCubeVertices

	glEnableVertexAttribArray(spCustom->a("texCoord"));
	glVertexAttribPointer(spCustom->a("texCoord"), 2, GL_FLOAT, false, 0, myCubeTexCoords); //Współrzędne teksturowania bierz z tablicy myCubeTexCoords

	glEnableVertexAttribArray(spCustom->a("cameraPosition"));
	glVertexAttribPointer(spCustom->a("cameraPosition"), 3, GL_FLOAT, false, 0, &cameraPosition); //Współrzędne wierzchołków bierz z tablicy birdColors

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex0);
	glUniform1i(spCustom->u("tex"), 0);
	glUniform3fv(spCustom->u("sunPosition"), 1, glm::value_ptr(cameraPosition));

	glDrawArrays(GL_TRIANGLES, 0, myCubeVertexCount);

	glDisableVertexAttribArray(spCustom->a("vertex"));
	glDisableVertexAttribArray(spCustom->a("texCoord"));
	glDisableVertexAttribArray(spCustom->a("cameraPosition"));
}

//Procedura rysująca zawartość sceny
void drawScene(GLFWwindow* window, Model* atat) {
	//************Tutaj umieszczaj kod rysujący obraz******************l
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glm::mat4 P = glm::perspective(glm::radians(50.0f), 1.0f, 1.0f, floor_size/10);
	glm::mat4 V = glm::lookAt(
		cameraPosition,
		cameraPosition + cameraLook,
		cameraUp);

	
	atat->drawModel(P, V);
	//std::cout << "CameraPos: " << cameraPosition[0] << " " << cameraPosition[1] << " " << cameraPosition[2] << std::endl;
	//std::cout << "Ilosc meshy: " << atat.meshes.size() << std::endl;
	//std::cout << skyboxFaces[0].c_str() << std::endl;

	// FLOOOR
	glm::mat4 M = glm::mat4(1.0f);

	M = glm::scale(M, glm::vec3(floor_size, floor_size, floor_size));
	
	spFloor->use();
	glUniformMatrix4fv(spFloor->u("P"), 1, false, glm::value_ptr(P)); //Załaduj do programu cieniującego macierz rzutowania
	glUniformMatrix4fv(spFloor->u("V"), 1, false, glm::value_ptr(V)); //Załaduj do programu cieniującego macierz widoku
	glUniformMatrix4fv(spFloor->u("M"), 1, false, glm::value_ptr(M)); //Załaduj do programu cieniującego macierz modelu
	glEnableVertexAttribArray(spFloor->a("vertex"));
	glVertexAttribPointer(spFloor->a("vertex"), 4, GL_FLOAT, false, 0, floorVerts);
	glEnableVertexAttribArray(spFloor->a("texCoord"));
	glVertexAttribPointer(spFloor->a("texCoord"), 2, GL_FLOAT, false, 0, floorTexCoords);
	glEnableVertexAttribArray(spFloor->a("normal"));
	glVertexAttribPointer(spFloor->a("normal"), 4, GL_FLOAT, false, 0, floorNormals); //Współrzędne wierzchołków bierz z tablicy birdColors
	glUniform1i(spFloor->u("tex"), 0);
	glActiveTexture(GL_TEXTURE0); 
	glBindTexture(GL_TEXTURE_2D, tex1); // texture bind
	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableVertexAttribArray(spFloor->a("vertex"));
	glDisableVertexAttribArray(spFloor->a("texCoord"));
	glDisableVertexAttribArray(spFloor->a("normal"));


	M = glm::mat4(1.0f);
	M = glm::scale(M, glm::vec3(floor_size, floor_size, floor_size));

	glDepthFunc(GL_LEQUAL); // Aby uniknąć problemów z z-buforem podczas renderowania skyboxa
	spSkybox->use();
	V = glm::mat4(glm::mat3(V)); // niech skybox przemieszcza się razem z kamerą; obcinamy macierz - rotacja zachowana, ale translacja skasowana
	glUniformMatrix4fv(spSkybox->u("P"), 1, false, glm::value_ptr(P)); //Załaduj do programu cieniującego macierz rzutowania
	glUniformMatrix4fv(spSkybox->u("V"), 1, false, glm::value_ptr(V)); //Załaduj do programu cieniującego macierz widoku
	glUniformMatrix4fv(spSkybox->u("M"), 1, false, glm::value_ptr(M)); //Załaduj do programu cieniującego macierz modelu
	glEnableVertexAttribArray(spSkybox->a("vertex"));
	glVertexAttribPointer(spSkybox->a("vertex"), 3, GL_FLOAT, false, 0, skyboxVertices);
	glActiveTexture(GL_TEXTURE0); glBindTexture(GL_TEXTURE_CUBE_MAP, tex2); // texture bind
	glUniform1i(spSkybox->u("tex"), 0);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	//glDepthMask(GL_TRUE); meh
	glDisableVertexAttribArray(spSkybox->a("vertex"));
	glDisableVertexAttribArray(spSkybox->a("texCoord"));
	glDisableVertexAttribArray(spSkybox->a("normal"));
	glDepthFunc(GL_LESS); // wracamy do domyślnego trybu z-bufora
	
	//texKostka(P, V, glm::mat4(1.0f));

	glfwSwapBuffers(window); //Przerzuć tylny bufor na przedni
}


int main(void)
{
	GLFWwindow* window; //Wskaźnik na obiekt reprezentujący okno
	Model atat;
	float angle = 0;
	glfwSetTime(0);

	glfwSetErrorCallback(error_callback);//Zarejestruj procedurę obsługi błędów

	if (!glfwInit()) { //Zainicjuj bibliotekę GLFW
		fprintf(stderr, "Nie można zainicjować GLFW.\n");
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(1500, 900, "OpenGL", NULL, NULL);  //Utwórz okno 500x500 o tytule "OpenGL" i kontekst OpenGL.

	if (!window) //Jeżeli okna nie udało się utworzyć, to zamknij program
	{
		fprintf(stderr, "Nie można utworzyć okna.\n");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window); //Od tego momentu kontekst okna staje się aktywny i polecenia OpenGL będą dotyczyć właśnie jego.
	glfwSwapInterval(1); //Czekaj na 1 powrót plamki przed pokazaniem ukrytego bufora

	if (glewInit() != GLEW_OK) { //Zainicjuj bibliotekę GLEW
		fprintf(stderr, "Nie można zainicjować GLEW.\n");
		exit(EXIT_FAILURE);
	}

	atat = initOpenGLProgram(window, atat); //Operacje inicjujące
	//Główna pętla
	while (!glfwWindowShouldClose(window)) //Tak długo jak okno nie powinno zostać zamknięte
	{
		drawScene(window, &atat); //Wykonaj procedurę rysującą
		glfwPollEvents(); //Wykonaj procedury callback w zalezności od zdarzeń jakie zaszły.
	}

	freeOpenGLProgram(window);

	glfwDestroyWindow(window); //Usuń kontekst OpenGL i okno
	glfwTerminate(); //Zwolnij zasoby zajęte przez GLFW
	exit(EXIT_SUCCESS);
}
