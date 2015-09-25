/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 13:56:19 by emammadz          #+#    #+#             */
/*   Updated: 2015/09/24 12:14:45 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void error_msg(int which)
{
	if (which == 0)
		std::cout << "you must enter a number" << std::endl;
	else if (which == 1)
		std::cout << "no car can drive that much..." << std::endl;
	else if (which == 2)
	{
		std::cout << "theta0 or theta1 are out of range" << std::endl;
		exit(0);
	}
	else if (which == 3)
	{
		std::cout << "File doesn't exist, is empty or can't be opened, therefore theta0 and theta1 equal 0 and the price will always be 0" << std::endl;
		exit (-1);
	}
	else if (which == 4)
	{
		std::cout << "File is invalid" << std::endl;
	}
	std::cout << "Enter a mileage: ";
	std::cin.clear();
}

void predict(int mileage, std::ifstream & file)
{
	double estimatePrice;
	double theta0;
	double theta1;
	double min;
	double max;
	std::string str;
	try
	{
		std::getline (file, str, '\n');
		theta0 = std::stod(str);
		std::getline (file, str, '\n');
		theta1 = std::stod(str);
		std::getline (file, str, '\n');
		min = std::stod(str);
		std::getline (file, str, '\n');
		max = std::stod(str);
	}
	catch (std::out_of_range & e)
	{
		error_msg(2);
	}
	catch (std::invalid_argument & e)
	{
		error_msg(4);
	}
	estimatePrice = theta0  + (theta1  * (static_cast<double>((mileage - min)) / (max - min)));
	std::cout.precision(10);
	if (mileage <= 0 || estimatePrice < 0)
		estimatePrice = 0;
	std::cout << "The estimated Price for " << mileage << " is " << estimatePrice << std::endl;
}

int main(void)
{
	int mileage;
	std::ifstream file("save.txt");
	std::string str;

	if (!file.is_open() || !file.good() || ((file.peek() == std::ifstream::traits_type::eof()) == 1))
		error_msg(3);
	std::cout << "Enter a mileage: "; 
	while (std::getline(std::cin, str, '\n'))
	{
		try
		{
			mileage = std::stoi(str);
			break;
		}
		catch (std::invalid_argument & e)
		{
			error_msg(0);
		}
		catch (std::out_of_range & e)
		{
			error_msg(1);
		}
	}
	if (!std::cin.eof())
		predict(mileage, file);
	file.close();
	return (0);
}

