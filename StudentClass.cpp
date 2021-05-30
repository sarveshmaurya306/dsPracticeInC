
class Student{
    public:
    int age;
    void setName(std::string your_name){
        this->your_name = your_name;
    }

    std::string getName(){
        return this->your_name;
    }
    Student(){
        std::cout << "hi welcome"<<std::endl;
    }
    ~Student(){
        std::cout << "bye"<<std::endl;
    }
    private:
    std::string your_name;
    
};