#include <string>


class FromImage { 
    public: 
        FromImage(const std::string& filename); 
        ~FromImage(); 

        void extractText(); 
    
    private:
        void extractImages(); 
        void extractTables(); 
};