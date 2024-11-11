#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <string>

using json = nlohmann::json;

int main() {
    // Crear un objeto JSON
    json j;
    j["nombre"] = "Carlos";
    j["edad"] = 28;
    j["intereses"] = {"fútbol", "cine", "programación"};

    // Guardar en un archivo
    std::ofstream o("persona.json");
    o << j.dump(4);
    o.close();

    // Leer desde el archivo
    std::ifstream i("persona.json");
    if (!i.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo 'persona.json'." << std::endl;
        return 1;
    }

    try {
        json j2;
        i >> j2;
        std::cout << j2.dump(2) << std::endl;
    } catch (const json::parse_error& e) {
        std::cerr << "Error de parseo de JSON: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
