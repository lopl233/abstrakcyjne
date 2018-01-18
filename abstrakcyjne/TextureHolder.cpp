#include <SDL.h> 
#include <SDL_image.h>
#include <map>  
#include <string>
#include <Windows.h>
#include <vector>

using namespace std;


class TextureHolder {
private:
	map<string , SDL_Texture*> textureMap;
	SDL_Renderer* renderer;
	void addTexture(const string filename) {

		string filePath = "textures/" + filename;

		SDL_Surface* surface = IMG_Load(&filePath[0u]);
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);

		textureMap[filename] = texture;

	}
	vector<string> getFileNames(const string folder)
	{
		vector<string> names;
		string search_path = folder + "/*.*";
		WIN32_FIND_DATA fd;
		HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd);
		if (hFind != INVALID_HANDLE_VALUE) {
			do {
				if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
					names.push_back(fd.cFileName);
				}
			} while (::FindNextFile(hFind, &fd));
			::FindClose(hFind);
		}
		return names;
	}

public:
	TextureHolder(SDL_Renderer* renderer):renderer(renderer) {

		vector<string> myvector = getFileNames("textures");
		for (auto it = myvector.begin(); it != myvector.end(); ++it)
			addTexture(*it);
	}
	 
	SDL_Texture* getTexture(const string filename) {
		return textureMap[filename];
	}


};