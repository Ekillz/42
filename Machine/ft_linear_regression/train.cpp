/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   train.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 14:33:33 by emammadz          #+#    #+#             */
/*   Updated: 2015/09/23 17:39:00 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void train(MultiMap *data)
{
	std::ofstream file("save.txt");
	std::ofstream file2("thetas.txt");
	MultiMap::iterator it;
	double theta0 = 0;
	double theta1 = 0;
	double sum = 0;
	double sum2;
	double cost0;
	double cost1;
	double m = data->size(); 
	int s = 1;

	std::cout << "LEARNING RATE: " << LEARNING_RATE << std::endl;
	for (; 1 == 1; ++s)
	{
		sum = 0;
		sum2 = 0;
		cost1 = 0;
		if (s % 10 == 0)
		{
			for (it = data->begin(); it != data->end(); ++it) 
			{
				cost1 += pow(((theta0 + (theta1 * it->second["km"])) - it->second["price"]), 2);
			}
			cost1 *= (1 / (2 * m));
			cost0 -= cost1;
			if (cost0 < (cost1 / (1000000 / LEARNING_RATE)))
			{
				std::cout << "It took " << s << " iterations to converge." << std::endl;
				break;
			}
		}
		cost0 = 0;
		for (it = data->begin() ; it != data->end(); ++it)
		{
			cost0 += pow(((theta0 + (theta1 * it->second["km"])) - it->second["price"]), 2);
			sum += (theta0 + (theta1 * it->second["km"])) - it->second["price"];
			sum2 += ((theta0 + (theta1 * it->second["km"])) - it->second["price"]) * it->second["km"];
		}
		cost0 *= (1 / (2 * m)); 
		theta0 -= (LEARNING_RATE * (1 / m) * sum);
		theta1 -= (LEARNING_RATE * (1 / m) * sum2);
		if (file2.is_open())
		{
			file2 << static_cast<int>(theta0) << "\n";
			file2 << static_cast<int>(theta1) << "\n";
		}
	}
	if (file.is_open())
	{
		file << theta0 << "\n";
		file << theta1 << "\n";
		it = data->begin();
		file << it->second["min"] << "\n"; 
		file << it->second["max"] << "\n"; 
		file.close();
	}
	else
		std::cout << "unable to open" << std::endl;
}

void scale(MultiMap *data)
{
	MultiMap::iterator it = data->begin();
	double min = it->second["min"];
	double max = it->second["max"];

	for (; it != data->end(); ++it)
	{
		it->second["km"] = ((it->second["km"] - min) / (max - min));
	}

}
void get_min_max(MultiMap *data)
{
	std::vector<int> vec;
	MultiMap::iterator it = data->begin();
	for (; it != data->end(); ++it)
	{
		vec.push_back(it->second["km"]);
	}
	it = data->begin();
	std::sort(vec.begin(), vec.end());
	it->second["min"] = vec.front();
	it->second["max"] = vec.back();
}

void get_data(char *av)
{
	MultiMap data;
	int i = 0;
	std::ifstream file(av);
	std::string str;
	if (!file.is_open())
	{
		std::cout << "File invalid" << std::endl;
		exit (-1);
	}
	std::getline (file, str, '\n');
	while (std::getline (file, str, '\n'))
	{
		data[i]["km"] = std::stoi(std::string(str, 0, str.find(',')));
		data[i]["price"] = std::stoi(std::string(str, str.find(',') + 1, str.length() - str.find(',')));
		i++;
	}
	get_min_max(&data);
	scale(&data);
	train(&data);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		get_data(av[1]);
		if (LEARNING_RATE >= 0.1)
			system("./graphic");
	}
	return (0);
}
