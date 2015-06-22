/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 18:17:46 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/19 15:53:46 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

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
	std::cout << std::endl << std::endl;
	NinjaTrap test3("emil3");
	test3.rangedAttack(str);
	test3.meleeAttack(str);
	std::cout << test3.name << " hit points: " << test3.hitPoints << std::endl;
	test3.takeDamage(20);
	std::cout << test3.name << " hit points: " << test3.hitPoints << std::endl;
	test3.takeDamage(95);
	std::cout << test3.name << " hit points: " << test3.hitPoints << std::endl;
	test3.beRepaired(40);
	std::cout << test3.name << " hit points: " << test3.hitPoints << std::endl;
	test3.beRepaired(70);
	std::cout << test3.name << " hit points: " << test3.hitPoints << std::endl;
	test3.ninjaShoebox(test);
	std::cout << test.name << "'s level is: " << test.level << std::endl;
	test3.ninjaShoebox(test2);
	std::cout << test2.name << "'s level is: " << test2.level << std::endl;
	test3.ninjaShoebox(test3);
	std::cout << test3.name << "'s level is: " << test3.level << std::endl;
	ClapTrap test4("emil4");
	test3.ninjaShoebox(test4);
	std::cout << test4.name << "'s level is: " << test4.level << std::endl;
	return (0);
}
