/**
 *\file EmployeException.h
 * \brief Fichier qui contient l'interface de la classe Electeur qui sert au maintien et à la manipulation des electeurs
 * \author Marc-Antoine Guay; Mustapha BOUHSEN
 */

#ifndef EMPLOYEEXCEPTION_H_
#define EMPLOYEEXCEPTION_H_
#include <stdexcept>

class PersonnException : public std::runtime_error{
public:
	PersonnException(const std::string& p_raison):
		std::runtime_error(p_raison){}
};

class PersonneDejaPresentException : public PersonnException
{
public:
	 PersonneDejaPresentException(const std::string& p_raison):
		 PersonnException(p_raison){}
};

class PersonneAbsenteException : public PersonnException
{
public:
	PersonneAbsenteException(const std::string& p_raison):
		PersonnException(p_raison){}
};

#endif /* EMPLOYEEXCEPTION_H_ */
