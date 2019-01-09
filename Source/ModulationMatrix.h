/*
  ==============================================================================

    ModulationMatrix.h
    Created: 31 Oct 2016 6:41:55pm
    Author:  dell

  ==============================================================================
*/

#ifndef MODULATIONMATRIX_H_INCLUDED
#define MODULATIONMATRIX_H_INCLUDED

/**
A modulation matrix that knows :
- all the instances that can be modulated and the list of the paramaters that can be modulated for each device.
- the modulators that can be used
It will have the look of a table with the following columns:
sources -> targets, modAmount, modType (multiply or add)


le rôle de la ModulationMatrix est d'informer une device que l'un de ses paramètres est modulé
et de lui envoyer la modulation et le modAmount
Si un paramètre est modulé par plusieurs modulateurs,
la modulationMatrix crée un buffer qui somme ces modulations, les clipes, etc

Fonctionnement:
Lorsqu'un paramètre est assigné à une modulation, la modMatrix prévient la device qui contien le paramètre
A chaque buffer, la device demande le modAmount et l'adresse du buffer et du modAmount
Lorsque le paramètre n'est plus modulé la modMatrix prévient la device
*/

//VOIR AUDIOPROCESSOR BUS?


#endif  // MODULATIONMATRIX_H_INCLUDED
