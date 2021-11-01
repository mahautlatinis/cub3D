/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:09:07 by user42            #+#    #+#             */
/*   Updated: 2021/04/08 10:09:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include "./libft/libft.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}
//Va etre appelee lorsqu'on va appuyer sur une touche a l interieur de la fenetre
//Key correspond au numero de touche
int     deal_key(int key, void *param)
{
    ft_putchar('X');
    //mlx_pixel_put(mlx_ptr, win_ptr, ...);
    return (1);
}

//Faire un putnbr pour afficher le numero de touche qu on a recupere

int main(void)
{
    //Mlx_init renvoie un void * qui correspond a l'identifiant de la connection au serveur graphique
    void *mlx_ptr;
    void *win_ptr;
    //Connexion au serveur graphique
    mlx_ptr = mlx_init();
    //Ouverture d'une fenetre
    win_ptr = mlx_new_window(mlx_ptr, 400, 500, "coucou");
    //On doit indiquer qu on veut pouvoir detecter si il y a eu un clic clavier
    //Attention il va y avoir des pointeurs sur fonction (de nos propres fonctions)
    mlx_key_hook(win_ptr, deal_key, (void *)0);
    //Fonction en charge de gerer les evenements - "On laisse la main au serveur graphique"
    mlx_loop(mlx_ptr);
    return (0);
}