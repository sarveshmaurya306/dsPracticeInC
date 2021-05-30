template <typename T, typename U>
class Pair{
    T x;
    U y;
    public:

    void setX(T x){
        this->x = x;
    }
        
    T getX(){
        return x;
    }
        
    void setY(U y){
        this->y = y;
    }
        
    U getY(){
        return y;
    }
        
};