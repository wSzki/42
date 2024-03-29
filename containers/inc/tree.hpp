/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:41:06 by wszurkow          #+#    #+#             */
/*   Updated: 2022/09/17 21:51:21 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

#include <cstddef>

// http://carl.seleborg.free.fr/cpp/cours/chap2/arbres.html
// https://cours.etsmtl.ca/SEG/FHenri/inf145/Suppl%C3%A9ments/arbres%20binaires.htm

//https://fr.wikipedia.org/wiki/Arbre_bicolore
//https://www.geeksforgeeks.org/c-program-red-black-tree-insertion/
//https://miashs-www.u-ga.fr/prevert/Prog/Java/CoursJava/arbresRougeNoir.html
//https://cours.etsmtl.ca/SEG/FHenri/inf145/Suppl%C3%A9ments/arbres%20binaires.htm
//
//
//On peut décrire le premier arbre binaire de la figure 1 ainsi :
// A = {1, {5, {0, Ø, Ø }, {3, Ø, Ø }}, {2, Ø, Ø }}
// Et le second de la façon suivante :
// A = {5, Ø, Ø}

#include <iostream>
namespace ft
{



	// NOTE destruction of node is handled by the tree
	template <typename T>
		class node
		{
			public:
				T data;
				node &parent;
				node &left;
				node &right;

				// Default Constructor
			public:
				node () : data(0), parent(NULL), left(NULL), right(NULL){
					std::cout << "Called\n";
				};

				// Constructor
				node (
						T data,
						node *parent = NULL,
						node *left = NULL,
						node *right = NULL
					 ):
					data(data),
					parent(parent),
					left(left),
					right(right) {
					std::cout << "Called\n";


					};
		};

	//template <typename Key, typename T, typename Compare, typename Alloc>
	template <typename Key, typename T >
		class tree
		{
			public :
				node<T> _root;
				node<T> _current;
				size_t  _nb_nodes;

				// NOTE Disables copy - why?
				tree(const tree &);
				tree & operator = (const tree &);

			public :

				typedef node<T> node_type;
				typedef node<T>* node_ptr;
				typedef node<T>& node_reference;
				typedef node<T> n;

				/* ---------------------- CONSTRUCTORS ---------------------- */
				tree (void) : _root(n(42)), _current(_root), _nb_nodes(0) {};
				~tree(void) {};

				n getRoot() const {return _root;}

				void insert_left(node_reference n, const T & val)
				{
					(void)val;
					n.left = node_ptr(42);
				}

				void insert(T val)
				{
					if (_root == NULL)
						_root = node_type(val);
					_current = _root;
				}

				/* ------------------------- ADDERS ------------------------- */
				int add_left  (const node_type & n) { _current->left  = n; };
				int add_right (const node_type & n) { _current->right = n; };

				/* ------------------------- MOVERS ------------------------- */
				int goto_root  (void) {_current = _current->_root;}
				int goto_left  (void) {_current = _current->left;}
				int goto_right (void) {_current = _current->right;}

				/* ------------------------- CLEAR -------------------------- */
				void clear(void); // TODO flushes tree

				/* ------------------------ GETTERS ------------------------- */

				// NOTE Get content of _current node
				T current_data (T &)  const {return _current->data;}
				// NOTE get number of elements in tree
				size_t leaves       (void) const; // TODO
				size_t size         (void) const {return _nb_nodes;}
				bool   empty        (void) const {return (size() == 0);}


				// Offre de parcours en modification.

				//inline void prefix(void (*f) (T &))
				//{ parcours_prefixe(racine, f);}

				//inline void infix(void (*f) (T &))
				//{ parcours_infixe(racine, f);}

				//inline void suffix(void (*f) (T &))
				//{ parcours_suffixe(racine, f);}

				//// METHODES DE CONSULTATION

				//// Offre de parcours en consultation.

				//inline void prefix(void (*f) (const T &)) const
				//{ parcours_prefixe(racine, f);}

				//inline void infix(void (*f) (const T &)) const
				//{ parcours_infixe(racine, f);}

				//inline void suffix(void (*f) (const T &)) const
				//{ parcours_suffixe(racine, f);}


				//inline int count_leaves() const     // Nombre de feuilles.
				//{ return compter_feuilles_arbre(racine);}

				//inline int depth() const  // Profondeur de l'arbre.
				//{ return profondeur_arbre(racine);}

		};
}
#endif
