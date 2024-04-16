#pragma once
#ifndef MESH_H


class Mesh {
public:
	std::vector<glm::vec4> verts;
	std::vector<glm::vec4> norms;
	std::vector<glm::vec2> texCoords;
	std::vector<unsigned int> indices;

	Mesh() {};

	Mesh(std::vector<glm::vec4> verts, std::vector<glm::vec4> norms, std::vector<glm::vec2> texCoords, std::vector<unsigned int> indices) {
		this->verts = verts;
		this->norms = norms;
		this->texCoords = texCoords;
		this->indices = indices;
	}

	void loadMesh(aiMesh* mesh) {
		for (int i = 0; i < mesh->mNumVertices; i++) { //Odczytanie i zapisanie do wektorów wierzcho³ków mesha
			aiVector3D vertex = mesh->mVertices[i]; //aiVector3D podobny do glm::vec3
			verts.push_back(glm::vec4(vertex.x, vertex.y, vertex.z, 1));
			aiVector3D normal = mesh->mNormals[i]; //Wektory znormalizowane
			norms.push_back(glm::vec4(normal.x, normal.y, normal.z, 0));

			aiVector3D texCoord = mesh->mTextureCoords[0][i];
			texCoords.push_back(glm::vec2(texCoord.x*16, texCoord.y*4));

		}
		for (int i = 0; i < mesh->mNumFaces; i++) { 
			aiFace& face = mesh->mFaces[i]; //face to jeden z wielok¹tów siatki
			for (int j = 0; j < face.mNumIndices; j++) {
				indices.push_back(face.mIndices[j]);
			}
		}


	}

	void drawMesh() { //rysowanie pojedyñczego meshu
		glEnableVertexAttribArray(spLambertTextured->a("vertex"));
		glVertexAttribPointer(spLambertTextured->a("vertex"), 4, GL_FLOAT, false, 0, verts.data()); //Wspó³rzêdne wierzcho³ków bierz z tablicy birdVertices

		glEnableVertexAttribArray(spLambertTextured->a("texCoord"));
		glVertexAttribPointer(spLambertTextured->a("texCoord"), 2, GL_FLOAT, false, 0, texCoords.data()); //Wspó³rzêdne wierzcho³ków bierz z tablicy birdColors

		glEnableVertexAttribArray(spLambertTextured->a("normal"));
		glVertexAttribPointer(spLambertTextured->a("normal"), 4, GL_FLOAT, false, 0, norms.data()); //Wspó³rzêdne wierzcho³ków bierz z tablicy birdColors

		//glEnableVertexAttribArray(spCustom->a("cameraPosition"));
		//glVertexAttribPointer(spCustom->a("cameraPosition"), 3, GL_FLOAT, false, 0, &cameraPosition); //Wspó³rzêdne wierzcho³ków bierz z tablicy birdColors

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, tex0);
		glUniform1i(spLambertTextured->u("tex0"), 0);

		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, tex0spec);
		glUniform1i(spLambertTextured->u("tex0spec"), 1);

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(int), &indices[0], GL_STATIC_DRAW);

		glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, indices.data());
		
		glDisableVertexAttribArray(spLambertTextured->a("vertex"));
		glDisableVertexAttribArray(spLambertTextured->a("texCoord"));
		glDisableVertexAttribArray(spLambertTextured->a("normal"));
	}
};

#endif