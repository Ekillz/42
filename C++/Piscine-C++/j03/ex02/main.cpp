/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 18:17:46 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/19 22:45:18 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	srand((unsigned int)time(NULL));
	FragTrap test("emil");
	std::string const & str = "ekillz";
	std::cout << test.name << " energy points: " << test.energyPoints << std::endl;
	test.vaulthunter_dot_exe(str);
	std::cout << test.name << " energy points: " << test.energyPoints << std::endl;
	test.vaulthunter_dot_exe(str);
	test.vaulthunter_dot_exe(str);
	test.vaulthunter_dot_exe(str);
	std::cout << test.name << " energy points: " << test.energyPoints << std::endl;
	test.vaulthunter_dot_exe(str);
	std::cout << test.name << " energy points: " << test.energyPoints << std::endl;
	test.rangedAttack(str);
	test.meleeAttack(str);
	std::cout << test.name << " hit points: " << test.hitPoints << std::endl;
	test.takeDamage(20);
	std::cout << test.name << " hit points: " << test.hitPoints << std::endl;
	test.takeDamage(95);
	std::cout << test.name << " hit points: " << test.hitPoints << std::endl;
	test.beRepaired(40);
	std::cout << test.name << " hit points: " << test.hitPoints << std::endl;
	test.beRepaired(70);
	std::cout << test.name << " hit points: " << test.hitPoints << std::endl;
	std::cout << std::endl << std::endl;
	ScavTrap test2("emil2");
	test2.rangedAttack(str);
	test2.meleeAttack(str);
	std::cout << test2.name << " hit points: " << test2.hitPoints << std::endl;
	test2.takeDamage(20);
	std::cout << test2.name << " hit points: " << test2.hitPoints << std::endl;
	test2.takeDamage(95);
	std::cout << test2.name << " hit points: " << test2.hitPoints << std::endl;
	test2.beRepaired(40);
	std::cout << test2.name << " hit points: " << test2.hitPoints << std::endl;
	test2.beRepaired(70);
	std::cout << test2.name << " hit points: " << test2.hitPoints << std::endl;
	test2.challengeNewcomer();
	test2.challengeNewcomer();
	test2.challengeNewcomer();
	test2.challengeNewcomer();

	return (0);
}
