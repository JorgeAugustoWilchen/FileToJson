#include <string>


class FromImage { 
    public: 
        FromImage(); 
        ~FromImage(); 

        std::string convertToJson(const std::string& filename);
    
    private:
        void extractText(); 
        void extractImages(); 
        void extractTables(); 
};