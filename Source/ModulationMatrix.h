/*
  ==============================================================================

    ModulationMatrix.h
    Created: 31 Oct 2016 6:41:55pm
    Author:  dell

  ==============================================================================
*/

#ifndef MODULATIONMATRIX_H_INCLUDED
#define MODULATIONMATRIX_H_INCLUDED
/*
Cette ModulationMatrix doit connaître toutes mes instances pouvant être modulées
et la liste des paramètres pouvant être modulés pour chaque device
et tout les modulateurs pouvant être utilisés
sources -> targets, modAmount, multiply, add


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
