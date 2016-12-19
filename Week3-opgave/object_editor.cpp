#include "object_editor.hpp"



object_editor::object_editor(sf::RenderWindow & window, std::string filename_object_data):
	window(window),
	filename_object_data(filename_object_data)
{
	try {
		for (;;) {
			screen_objects.push_back(screen_object_read(input));
		}
	}
	catch(end_of_file){
		//continue
	}
}

void object_editor::update() {}



screen_objects* object_editor::screen_object_read(std::ifstream & input){
	sf::Vector2f position;
	std::string name;
	filename_object_data >> position >> name;

	if (name == "CIRCLE") {
		sf::Color color;
		float radius;
		filename_object_data >> color >> radius;
		return new circle(window, position, color, radius);
	}
	else if (name == "RECTANGLE") {
		sf::Color color;
		sf::Vector2f end_position;
		filename_object_data >> color >> end_position;
		return new rectangle(window, position, color, end_position);

	}
	else if (name == "PICTURE") {
		std::string fileName;
		filename_object_data >> fileName >> position;
		return new picture(window, fileName, position);
	}
	//else if (name == "LINE") {
	//	sf::Color color;
	//	sf::Vector2f size;
	//	float rotation;
	//	input >> color >> size >> rotation;
	//	return new line(position, color, size, rotation);
	//}
	else if (name == "") {
		throw end_of_file();
	}
	throw unknown_shape(name);
}

void object_editor::redraw(sf::RenderWindow &window, std::list<screen_objects*> screen_objects) {
	window.clear();
	for (auto screen_obj : screen_objects) {
		screen_obj->draw(window);
	}
	window.display();
}

void object_editor::save(std::list<screen_objects*> screen_objects) {
	std::ofstream output("objects.txt");
	for (auto screen_obj : screen_objects) {
		output << *screen_obj << std::endl;
	}
	output.close();
}

sf::Vector2f object_editor::Vector2f_from_Vector2i(sf::Vector2i vector) {
	return sf::Vector2f(static_cast<float>(vector.x), static_cast<float>(vector.y));
}





object_editor::~object_editor(){
}
