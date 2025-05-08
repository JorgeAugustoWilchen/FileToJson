#include "frompdf.hpp"

FromPDF::FromPDF()
{
}

FromPDF::~FromPDF()
{
}

std::string FromPDF::convertToJson(const std::string& filePath)
{
    std::string outputJsonPath = filePath.substr(0, filePath.find_last_of('.')) + ".json";

    poppler::document *doc = poppler::document::load_from_file(filePath);
    if (!doc) {
        std::cerr << "Erro ao carregar o PDF: " << filePath << std::endl;
        return "";
    }

    json j;

    for (int i = 0; i < doc->pages(); ++i) {
        poppler::page *page = doc->create_page(i);
        if (page) {
            std::string text(page->text().to_utf8().data(), page->text().to_utf8().size());
            j["pages"][i]["text"] = text;
        }
    }

    std::ofstream out(outputJsonPath);
    if (!out) {
        std::cerr << "Erro ao criar arquivo JSON: " << outputJsonPath << std::endl;
        return "";
    }

    out << j.dump(4);
    return outputJsonPath;
}