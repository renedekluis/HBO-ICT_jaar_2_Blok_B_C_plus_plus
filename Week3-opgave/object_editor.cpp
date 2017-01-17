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
	} catch(end_of_file){
		std::cout << "end of file reached";
		//continue
	} catch (std::exception & problem) {
		std::cout << problem.what();
	}
	std::cout << object_list.size();
}

void object_editor::update() {
	if (check_mouse()) {
		sf::Vector2f position_of_mouse = get_mouse_position(window);
		for (auto list : object_list) {
			if(list->get_bounds().contains(position_of_mouse)){
				list->is_selected();
				break;
			}
			else {
				list->cancel_selected();
			}
		}
	}
	for (auto list : object_list) {
		list->move(get_move_direction_from_button_keys());
		list->draw(window);
	}
}


screen_objects* object_editor::screen_object_read(std::ifstream & input){
	sf::Vector2f position;
	std::string name;
	input >> position >> name;

	if (name == "CIRCLE") {
		sf::Color color = sf::Color::Green;
		int radius;
		input >> color >> radius;
		return new circle(position, color, radius);
	}
	else if (name == "RECTANGLE") {
		sf::Color color;
		sf::Vector2f end_position;
		input >> color >> end_position;
		
		return new rectangle(position, color, end_position);
	}
	else if (name == "PICTURE") {
		std::string fileName;
		input >> fileName;
		return new picture(fileName, position);
	}
	else if (name == "LINE") {
		sf::Color color;
		sf::Vector2f size;
		float rotation;
		input >> color >> size >> rotation;
		return new line(position, color, size, rotation);
	}
	else if (name == "") {
		throw end_of_file();
	}
	throw unknown_shape(name);
}


void object_editor::save() {
	std::ofstream output(filename_object_data);
	for (auto screen_obj : object_list) {
		output << screen_obj->to_string();
		output << "\n";
	}
	output.close();
}

sf::Vector2f object_editor::Vector2f_from_Vector2i(sf::Vector2i vector) {
	return sf::Vector2f(static_cast<float>(vector.x), static_cast<float>(vector.y));
}



object_editor::~object_editor(){
}
