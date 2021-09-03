/*
    Tasks: 0
*/

#include <iostream>
#include <cstring>
//#include </home/MarF1/ejudge/4_SEM/up06/test.h>

class Str
{
private:
    size_t size = 0, len = 0;
    char *str;
public:
/*    Str (size_t s);
    Str (const std::string &str1);
    ~Str ();
    explicit Str (const Str &X);
    size_t get_len() const;
    size_t get_size() const;
    char *get_str();
    Str &operator =(const Str &X);
  */  friend Str *operator +(const Str &X);
//    Str &operator +=(const Str &X);

//----------------------------------//
Str (size_t s = 100): size(s)   //
{                                     // work correctle honestly
std::cout << "xyeta";
    str = new char[size];            //
}                                   // 
//-----------------------------------
Str (const std::string &str1)  //         
{                                    //              
std::cout << 0;
    if (size) {                       //           
        delete []str;                  //           
    }                                  // work correctly honestly         
    len = str1.size();                //           
    size = len + 1;                  //           
    str = new char[size];           //                      
    strcpy(str, str1.c_str());     //                          
}                                 //
//---------------------------------
~Str ()                     //
{                                 //
    if (size) {                    //
        delete []str;              // wch
    }                             //
}                                //
//--------------------------------
Str (const Str &X)          //
{   
std::cout << 1;
    if (size) {                    //
        delete []str;               //
    }                                // wch 
    len = X.len;                    //
    size = X.size;                 //
    str = new char[size];         //
    strcpy(str,X.str);           //
}                               //
//-------------------------------
size_t get_size() const   //
{                               //
    return size;                 //
}                                 //
                                   //  
size_t get_len() const         //
{                                    //
    return len;                      // wch
}                                   //
                                   //
char *get_str()              //
{                                //
    return str;                 //
}                              //
//----------------------------------
Str operator =(const Str &X) //
{                                   //
std::cout << 2;
    len = X.len;                     //
    size = X.size;                    // wch
    str = X.str;                     //
    return *this;                   //
}                                  //
//-------------------------------------------
Str operator +=(const Str &X)        //            
{                                           //             
std::cout << 4;
    size_t i = 0;                            //          
    char *str1 = new char[len + X.size];      //             
    for (; i < len; ++i) {                     //         
        str1[i] = str[i];                       //      
    }                                            //         
    for (; i < len + X.size; ++i) {               //        
        str1[i] = X.str[i - len];                  //      
    }                                              //  wch
    if (size) {                                   //     
        delete []str;                            //    
    }                                           //     
    size += X.size - 1;                        //            
    len += X.len;                             //     
    str = str1;                              //      
    return *this;                           //   
}                                          //      
//------------------------------------------
};
Str *operator +(const Str &Y, const Str &X) // !!!!!!!!!!!!!! using *
{                                            //
std::cout << 3;
    Str *out = new Str(Y);                    // 
    *out += X;                                //  wch
    return out;                              //
}                                           //
//------------------------------------------

class String
{
public:
    int pid;
    Str *str;
/*    String ();
    String (const std::string str1);
    String (const std::string str1, const std::string str2, int p);
    String (const String &X);
    ~String ();
    String &operator =(const std::string &X);
    String &operator =(const String &X);
    operator const char *() const;
  */  friend String operator +(const String &Y, const std::string &X);
  //  String &operator +=(const char &X);
    friend String operator +(const String &X, const String &Y);
  //  String &operator +=(const String &X);
    char &operator [] (const size_t index)
    {
        if (index < 0 || index >= str->get_len()) {
            exit(1);
        }
        if (!pid) {
            str = new Str(*str);
        }
        return str->get_str()[index];
    }
    String (const char *x) {}

String(): pid(1)
{
std::cout << 5;
    str = new Str();
}

String (const std::string str1): pid(1)
{
std::cout << 6;
    str = new Str(str1);
}

String (const std::string str1, const std::string str2, int p = 1): pid(p)
{
std::cout << 7;
    str = new Str(str1 + str2);
}

String (const String &X)
{
std::cout << 8;
    pid = 1;
    str = new Str(*(X.str));
}

~String ()
{
    if (pid) {
        delete str;
    }
}

String &operator =(const char &X)
{
std::cout << 9;
    delete str;
    pid = 1;
    str = new Str(X);
    return *this;
}

String &operator =(const String &X)
{
std::cout << 10;
    delete str;
    if (X.pid == 2) {
        pid = 1;
    } else {
        pid = 0;
    }
    str = X.str;
    return *this;
}

operator const char *() const
{
    return str->get_str();
}

String &operator +=(const char &X)
{
std::cout << 12;
    *str += Str(X);
    return *this;
}

String &operator +=(const String &X)
{
std::cout << 14;
    *str += *(X.str);
    return *this;
}
};
String operator +(const String &Y, const std::string &X)
{
std::cout << 11;
    String out(Y);
    out.pid = 2;
    out += String(X);
    return out;
}
String operator +(const String &X, const String &Y)
{
std::cout << 13;
    String out(X);
    out.pid = 2;
    out += Y;
    return out;
}


using namespace std;

int main()
{
/*
    String out1;
    string str1, str2, str3;
    std::cin >> str1 >> str2 >> str3;
    String out2(str1);
    String out3(str2 + str3);
    out1 = out2;
*/
    String out3, out1 = "abc";
/*    String out2 = out1;
std::cout << "chek" << std::endl;
    out3 = out1;
std::cout << "chek" << std::endl;
    out2 += "aaa";
std::cout << "chek" << std::endl;
    out3[1] = 'f';

//--------------exit-----------------   
    std::cout << out1.str->get_str() << ' ' ;
    std::cout << out1.str->get_len() << ' ' ;
    std::cout << out1.str->get_size() << std::endl;
    std::cout << out2.str->get_str() << ' ' ;
    std::cout << out2.str->get_len() << ' ' ;
    std::cout << out2.str->get_size() << std::endl;
    std::cout << out3.str->get_str() << ' ' ;
    std::cout << out3.str->get_len() << ' ' ;
    std::cout << out3.str->get_size() << std::endl;
*/}

