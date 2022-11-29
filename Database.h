//Author weCode
//Database.h

#define DATABASE_H

template <typename T>
class Database {
    private:
        T *data;
        int arraylength;
        int listsize;
        void resize();//
        bool needtoresize();

    public:
        Database();//default constructor
        int getSize();
        int findElement(T);
        T get(int);

        void print();
        void add(T);
        void insert(int, T);
        void modify(int, T);//depending change T at certain index
        void modify(T,T); //change T to new T
        void deleteElement(T);
        void deleteElement(int);
        T getElement(std::string);
        T getElement(int);
        void toString();

};