# Задание №0 (вводное). Раздельная компиляция и пространства имен (namespaces)


## З⃣а⃣д⃣а⃣ч⃣а⃣     №⃣ 0⃣а⃣


Познакомьтесь с раздельной компиляцией и пространством имен в C++. 
В качестве примера используйте следующую программу:


Р⃣е⃣а⃣л⃣и⃣з⃣а⃣ц⃣и⃣я⃣    к⃣о⃣д⃣а⃣:

* ## File module1.h:

        #include <string>

        namespace Module1
        {
          std::string getMyName();
        }
    
* ## File module1.cpp
    
    
        #include "module1.h"

        namespace Module1
        {
          std::string getMyName()
          {
            std::string name = "John";
            return name;
          }
        }

*  ## File module2.h:

        #include <string>

        namespace Module2
        {
          std::string getMyName();
        }

* ## File module2.cpp
        #include "module2.h"

        namespace Module2
        {
          std::string getMyName()
          {
            std::string name = "James";
            return name;
          }
        }

* ## File main.cpp:
    
        #include "module1.h"
        #include "module2.h"
        #include <iostream>

        int main(int argc, char** argv)
        {
          std::cout <<  "Hello world!" << "\n";

          std::cout << Module1::getMyName() << "\n";
          std::cout << Module2::getMyName() << "\n";

          using namespace Module1;
          std::cout << getMyName() << "\n"; // (A)
          std::cout << Module2::getMyName() << "\n";

          //using namespace Module2; // (B)
          //std::cout << getMyName() << "\n"; // COMPILATION ERROR (C)

          using Module2::getMyName;
          std::cout << getMyName() << "\n"; // (D)
        }
    
##  З⃣а⃣д⃣а⃣ч⃣а⃣     №⃣ 0⃣ b⃣
    
> С тестовой программой нужно выполнить следующие действия:
Собрать программу и убедиться, что на каждый *.cpp файл создается отдельный объектный файл с тем же именем (для Visual Studio, например, в папке Debug будут создаваться файлы с расширением *.obj). 

Убедиться, что при изменении одного *.cpp файла и пересборке проекта обновляется только соответствующий ему объектный файл (дата изменения других объектных файлов останется прежней)

> Объяснить, что выведется при выполнении строк с комментариями (А) и (D) в main.cpp

Убедиться, что раскомментирование строк (B) и (C) в main.cpp приводит к ошибке компиляции. Объяснить, почему эта ошибка происходит, и предложить пути её устранения.

> Добавить в проgграмму еще одну функцию getMyName(), возвращающую имя Peter. Обернуть её в еще одно пространство имён.

Объяснить, как можно избавиться от необходимости писать std::cout и вместо этого писать просто cout.
