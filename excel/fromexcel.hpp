#include <string>


class FromExcel
{ 
    public:
        FromExcel(const std::string& filename);
        ~FromExcel();
        void extractText();
    
    private:
        void extractImages();
        void extractTables();
};