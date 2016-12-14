#include "object_editor.hpp"



object_editor::object_editor(sf::RenderWindow & window, char* filename_object_data):
	window(window),
	filename_object_data(filename_object_data)
{
	FILE * object_data;
	int ch;
	string data_stream = "";
	int n = 0;
	string name = "";
	sf::Vector2f position;
	string color = "";
	fopen_s(&object_data, filename_object_data , "r");
	if (!object_data) {
		perror("Error while opening file");
	}
	else {
		while (( ch = fgetc(object_data))  != EOF) {
			if (ch == ' ' || ch == '\n' || ch == ',' ) { // name
				if (n == 0) {
					name = data_stream;
					n++;
				}
				else if (n == 1) { // position
					if (ch == ','){
						std::string::size_type sz;   
						position.x = std::stof(data_stream, &sz);
					}
					else {
						std::string::size_type sz;    
						position.y = std::stof(data_stream, &sz);
						n++;
					}
				}
				else if(n == 2){ //color
					color = data_stream;
					n++;
				}

				data_stream = "";
				if (ch == '\n') {
					std::cout << name << " " << position.x << "," << position.y << " " << color << "\n";
					n = 0;
				}
			}
			else {
				data_stream = data_stream + char(ch);
			}


			
		}
	}

	
	_fcloseall();

}

void object_editor::update() {}

object_editor::~object_editor(){
}
