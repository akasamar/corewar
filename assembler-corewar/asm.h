/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 21:35:05 by osapon            #+#    #+#             */
/*   Updated: 2018/08/21 20:31:16 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# define N_E 1
# define C_T 2
# define CMD 4
# define PROG_NAME_LENGTH (128)
# define COMMENT_LENGTH (2048)

# include "op.h"
# include "libft/ft_printf.h"
# include "libft/get_next_line.h"

int					g_line_numb;
int					g_fd;
int					g_flag_nolbl;
int					g_flag_op_lbl;
static const char	*g_operations[] = {
	"lfork",
	"live",
	"lldi",
	"zjmp",
	"fork",
	"add",
	"sub",
	"and",
	"xor",
	"ldi",
	"sti",
	"lld",
	"aff",
	"st",
	"or",
	"ld",
	NULL
};

typedef struct		s_cmd
{
	char			*name;
	int				value;
	int				arg_size;
	int				type_arg;
	struct s_cmd	*next;
}					t_cmd;

typedef struct		s_lbl
{
	char			*name;
	struct s_lbl	*next;
}					t_lbl;

typedef struct		s_asm
{
	int				type;
	int				flabel;
	int				opcode;
	int				octal_codage;
	char			*val;
	t_cmd			*cmd;
	t_lbl			*label;
	struct s_asm	*next;
	int				size;
}					t_asm;

void				ft_get_opcode_and_name(t_asm **tmp, char *temp);
void				ft_asm(char *file, t_asm **im_asm);
t_asm				*get_name_or_comment(void);
void				skip_empty_lines(char **line);
void				trim_end_spaces(char **name);
void				clear_comments(char **str);
char				*ft_trim(char *src);
void				error_print(char *text, int line);
char				*error_manager_text(int index);
char				*get_name_comment(char **line, int *sign);
int					is_full(char *line, int *sign);
void				ft_find_op_line_in_tab(char *op, char **op_line);
char				*get_of_spaces(char *line);
int					ft_codage_op_sum_labels(t_asm *par);
int					ft_create_file_dot_cor(char *old_path);
void				ft_fill_cor_file(t_asm *par);
int					ft_link_to_label_size(char *str);
void				del_options(char **str);
void				ft_skip(char **str);
int					option_length(char *str);
int					assigning_option_values(char *str, int i, t_cmd **im_asm);
int					label_name(char *temp);
t_lbl				*get_labels(char **temp, t_lbl *im_asm);
const char			*get_command_name(char *str);
void				del_args(char *name, char **str);
int					prep_line(char **line, char **temp);
void				clear_label(char **str);
int					link_to_label(char *temp);
void				ft_is_t_reg_t_dir(char **op_line);
void				ft_is_t_reg(char **op_line);
void				ft_is_label_chars(char **op_line);
int					ft_is_num(char *op_line);
void				ft_is_t_dir(char **op_line);
void				ft_check_args_amount(t_op tab, char *op_line);
void				ft_move_through_args_to_codage(t_asm *par);
void				ft_count_op_sum(t_asm *par);
int					ft_compare_labels(char *label_name, t_lbl *temp_label);
int					ft_find_distance_size(t_asm *par, int position, int enter);
void				ft_fill_magic_header(void);
t_cmd				*get_commands(char *temp, t_asm *im_asm);
int					is_operation(char *line);
int					commands(char *temp);
int					check_for_op(char *temp);

#endif
