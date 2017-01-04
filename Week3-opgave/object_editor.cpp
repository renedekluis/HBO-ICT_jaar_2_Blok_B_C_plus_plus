#include "object_editor.hpp"


object_editor::object_editor(sf::RenderWindow & window, std::string filename_object_data):
	window(window),
	filename_object_data(filename_object_data)
{
	input.open(filename_object_data);
	if (!input.is_open()) {
		std::cout << "No file";
	}

	try {
		for (;;) {
			object_list.push_back(screen_object_read(input));
		}
	}
	catch(end_of_file){
		//continue
	}
}

void object_editor::update() {
	if (check_mouse()) {
		sf::Vector2f position_of_mouse = get_mouse_position(window);
		for (auto list : object_list) {
			if(list->get_bounds().contains(position_of_mouse)){
				list->is_selected();
			}
			else {
				list->cancel_selected();
			}
		}
	}
	for (auto list : object_list) {
		list->move(get_move_direction_from_button_keys());
		list->draw();
	}
	
	

}



screen_objects* object_editor::screen_object_read(std::ifstream & input){
	sf::Vector2f position;
	std::string name;
	input >> position >> name;

	if (name == "CIRCLE") {
		sf::Color color;
		float radius;
		input >> color >> radius;
		return new circle(window, position, color, radius);
	}
	else if (name == "RECTANGLE") {
		sf::Color color;
		sf::Vector2f end_position;
		input >> color >> end_position;
		return new rectangle(window, position, color, end_position);

	}
	else if (name == "PICTURE") {
		std::string fileName;
		input >> fileName >> position;
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



void object_editor::save(std::vector<screen_objects*> screen_objects) {
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
	save(object_list);
}
