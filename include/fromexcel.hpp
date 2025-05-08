#include <string>


class FromExcel
{ 
    public:
        FromExcel();
        ~FromExcel();
        
        std::string convertToJson(const std::string& filename);
    
    private:
        void extractText(const std::string& filename);
        void extractImages();
        void extractTables();
};