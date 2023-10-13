/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_errors.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 09:30:09 by qdam              #+#    #+#             */
/*   Updated: 2023/10/13 17:50:49 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_ERRORS_H
# define CUB3D_ERRORS_H

/*	==== LAUNCH MESSAGES ==== */
# define ARG_ERROR		        "Must have a .cub file as argument"
# define NAME_ERROR		        "A .cub file is required"
# define READ_ERROR		        "\033[0;31mCannot be opened or is empty\033[0m"
# define UNKN_ERROR		        "Unknown error"

/*	==== PARSER MESSAGES ==== */
# define PARSER_XPM_EXT			"All texture files must have XPM extension"
# define PARSER_XPM_OPN			"Cannot open one of the texture files"
# define PARSER_LINE_FMT		"A line is not correctly formatted"
# define PARSER_MAP_NOT_RDY		"Not enough information before parsing map"
# define PARSER_MAP_CHAR		"Map contains an invalid character"
# define PARSER_COLOR_LINE_ELEM	"A color line has too many or too few elements"
# define PARSER_COLOR_LINE_CHAR	"A color line contains non-numeric characters"
# define PARSER_COLOR_LINE_FMT	"A color line is wrongly formatted"
# define PARSER_COLOR_ONCE		"F and C should only be set once"
# define PARSER_COLOR_RANGE		"Color must be R,G,B between 0 and 255"
# define PARSER_TEXTURE_LINE	"Texture line error or direction already set"

/*	==== MALLOC MESSAGES ==== */
# define MALLOC_SPLIT	        "Malloc error during split"
# define MALLOC_STRDUP	        "Malloc error while parsing cub map (strdup)"
# define MALLOC_LSTNEW	        "Malloc error while parsing cub map (lstnew)"
# define MALLOC_COLLINE	        "Malloc error while parsing color line"
# define MALLOC_CHARMAP	        "Malloc error while creating map in game init"
# define MALLOC_TEXTURE	        "Malloc error while initializing wall textures"

/*	==== CUBMAP MESSAGES ==== */
# define CUBMAP_NULL	        "Map is NULL"
# define CUBMAP_ROW_INV	        "A map row is not valid"
# define CUBMAP_DEF_DIR	        "No default direction found"

/*	==== GAME AND GRAPHICS MESSAGES ==== */
# define GRAPHICS_INIT			"MinilibX initialization failed"
# define WINDOW_INIT			"Cannot create new window"
# define WINDOW_IMG_INIT		"Impossible to create main image"
# define TEXTURE_CORRUPT		"One of the texture files corrupted"

#endif
