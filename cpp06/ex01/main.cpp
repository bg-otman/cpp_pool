#include "Serializer.hpp"

int main() {
    Data mydata;
    
    mydata.name = "Othmane";
    mydata.age = 23;

    uintptr_t result = Serializer::serialize(&mydata);
    Data* deserialized_data = Serializer::deserialize(result);

    std::cout << "mydata.name : " << mydata.name << std::endl;
    std::cout << "mydata.age : " << mydata.age << std::endl;

    std::cout << "deserialized_data.name : " << (*deserialized_data).name << std::endl;
    std::cout << "deserialized_data.age : " << (*deserialized_data).age << std::endl;

    std::cout << "mydata addresse : " << &mydata << std::endl;
    std::cout << "deserialized_data addresse : " << deserialized_data << std::endl;

    return 0;
}
