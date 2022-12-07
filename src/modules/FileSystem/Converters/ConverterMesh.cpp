#include "../Converters.h"
#include "../../../helpers/C_AABB.h"
#include <src/modules/Render/RendererTypes.h>

#include <src/modules/ECS/ComponentsIncludeAll.h>

void ConvertAssimpMesh(const aiMesh* aimesh, NIMesh& mesh, Entity* parent, Entity* GameObject) {
	mesh.vertices.resize(aimesh->mNumVertices);
	memcpy(mesh.vertices.data(), aimesh->mVertices, aimesh->mNumVertices * sizeof(float3));
	
	if (aimesh->HasNormals()) {
		mesh.normals.resize(aimesh->mNumVertices);
		memcpy(mesh.normals.data(), aimesh->mNormals, aimesh->mNumVertices * sizeof(float3));
	}

	if (aimesh->HasFaces()) {
		mesh.indices.resize(aimesh->mNumFaces * 3);
		for (int i = 0; i < aimesh->mNumFaces; ++i) {
			memcpy(&mesh.indices[i * 3], aimesh->mFaces[i].mIndices, sizeof(uint32_t) * 3);
		}
	}
	
	// Only allow 1 set of uvs for now
	if (aimesh->HasTextureCoords(0)) {
		mesh.uvs.resize(aimesh->mNumVertices);
		if (aimesh->mNumUVComponents[0] == 2) {
			for (int i = 0; i < aimesh->mNumVertices; ++i) {
				memcpy(&mesh.uvs[i], &aimesh->mTextureCoords[0][i], sizeof(float2));
			}
		}
		else {
			memcpy(mesh.uvs.data(), aimesh->mTextureCoords[0], aimesh->mNumVertices * sizeof(float3));
		}
	}

	// TODO: Base Color / Bounding Box / 
	Entity* entityAux = App->ecs->AddEntity(GameObject->id);

	C_AABB* component = entityAux->AddComponent<C_AABB>();
	memcpy(entityAux->name, "aabb", sizeof(char) * 4);
	AABB* aux = new AABB();
	aux->SetFrom(mesh.vertices.data(), mesh.vertices.size());
	component->aabb = aux;
}


