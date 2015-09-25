/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 14:00:41 by emammadz          #+#    #+#             */
/*   Updated: 2015/09/24 14:17:54 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <map>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <vector>

// GRAPHIC //
#include "mlx/mlx.h"

#define LEARNING_RATE 0.1

typedef std::map<int,std::map<std::string, double> > MultiMap;

#endif 
