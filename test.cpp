
#include <iostream>
#include <cson/cson.hpp>

namespace test 
{
CSON_LABEL(name);
CSON_LABEL(age);
CSON_LABEL(work);
CSON_LABEL(dict);
CSON_LABEL(fun);
CSON_LABEL(items);
}

int main()
{
	using namespace test;

	auto x = cson
	(
	 	name = "Rafi", 
		age = 55,
		dict = cson
		(
			name = 1947, 
			age = "The type of age is deduced now which is std::string", 
			fun = [](std::string const & name) { std::cout << "Hello " << name << std::endl; },
			items = {"Shaan", "udit", "Sonu"}
		),
		fun = {1,2,3,4}, 
		work = "Singing"
	);

	x.dict.fun("Sarfaraz Nawaz");

	std::cout << x.name << "," << x.age <<"," << x.work << std::endl;
	x.name="Mukesh";
	x.age++; //well it is int
	std::cout << x.name << "," << x.age <<"," << x.work << std::endl;

	std::cout << x << std::endl;
	std::cout << x[work] << std::endl;

	std::cout << x[dict][age] << std::endl;
	std::cout << x.dict[age] << std::endl;
	std::cout << x[dict].age << std::endl;

	for(auto const & key : x.keys())
		std::cout << "key => " << key << std::endl;

}
