/* ----------------------------------------------------------------------------------------------- */
/*   Copyright (c) 2014 - 2017 by Axel Kenzo, axelkenzo@mail.ru                                    */
/*   All rights reserved.                                                                          */
/*                                                                                                 */
/*  Разрешается повторное распространение и использование как в виде исходного кода, так и         */
/*  в двоичной форме, с изменениями или без, при соблюдении следующих условий:                     */
/*                                                                                                 */
/*   1. При повторном распространении исходного кода должно оставаться указанное выше уведомление  */
/*      об авторском праве, этот список условий и последующий отказ от гарантий.                   */
/*   2. При повторном распространении двоичного кода должна сохраняться указанная выше информация  */
/*      об авторском праве, этот список условий и последующий отказ от гарантий в документации     */
/*      и/или в других материалах, поставляемых при распространении.                               */
/*   3. Ни имя владельца авторских прав, ни имена его соратников не могут быть использованы в      */
/*      качестве рекламы или средства продвижения продуктов, основанных на этом ПО без             */
/*      предварительного письменного разрешения.                                                   */
/*                                                                                                 */
/*  ЭТА ПРОГРАММА ПРЕДОСТАВЛЕНА ВЛАДЕЛЬЦАМИ АВТОРСКИХ ПРАВ И/ИЛИ ДРУГИМИ СТОРОНАМИ "КАК ОНА ЕСТЬ"  */
/*  БЕЗ КАКОГО-ЛИБО ВИДА ГАРАНТИЙ, ВЫРАЖЕННЫХ ЯВНО ИЛИ ПОДРАЗУМЕВАЕМЫХ, ВКЛЮЧАЯ, НО НЕ             */
/*  ОГРАНИЧИВАЯСЬ ИМИ, ПОДРАЗУМЕВАЕМЫЕ ГАРАНТИИ КОММЕРЧЕСКОЙ ЦЕННОСТИ И ПРИГОДНОСТИ ДЛЯ КОНКРЕТНОЙ */
/*  ЦЕЛИ. НИ В КОЕМ СЛУЧАЕ НИ ОДИН ВЛАДЕЛЕЦ АВТОРСКИХ ПРАВ И НИ ОДНО ДРУГОЕ ЛИЦО, КОТОРОЕ МОЖЕТ    */
/*  ИЗМЕНЯТЬ И/ИЛИ ПОВТОРНО РАСПРОСТРАНЯТЬ ПРОГРАММУ, КАК БЫЛО СКАЗАНО ВЫШЕ, НЕ НЕСЁТ              */
/*  ОТВЕТСТВЕННОСТИ, ВКЛЮЧАЯ ЛЮБЫЕ ОБЩИЕ, СЛУЧАЙНЫЕ, СПЕЦИАЛЬНЫЕ ИЛИ ПОСЛЕДОВАВШИЕ УБЫТКИ,         */
/*  ВСЛЕДСТВИЕ ИСПОЛЬЗОВАНИЯ ИЛИ НЕВОЗМОЖНОСТИ ИСПОЛЬЗОВАНИЯ ПРОГРАММЫ (ВКЛЮЧАЯ, НО НЕ             */
/*  ОГРАНИЧИВАЯСЬ ПОТЕРЕЙ ДАННЫХ, ИЛИ ДАННЫМИ, СТАВШИМИ НЕПРАВИЛЬНЫМИ, ИЛИ ПОТЕРЯМИ ПРИНЕСЕННЫМИ   */
/*  ИЗ-ЗА ВАС ИЛИ ТРЕТЬИХ ЛИЦ, ИЛИ ОТКАЗОМ ПРОГРАММЫ РАБОТАТЬ СОВМЕСТНО С ДРУГИМИ ПРОГРАММАМИ),    */
/*  ДАЖЕ ЕСЛИ ТАКОЙ ВЛАДЕЛЕЦ ИЛИ ДРУГОЕ ЛИЦО БЫЛИ ИЗВЕЩЕНЫ О ВОЗМОЖНОСТИ ТАКИХ УБЫТКОВ.            */
/*                                                                                                 */
/*   akrypt.h                                                                                      */
/* ----------------------------------------------------------------------------------------------- */
 #ifndef AKRYPT_H
 #define AKRYPT_H

/* ----------------------------------------------------------------------------------------------- */
 #include <stdio.h>
 #include <errno.h>
 #include <getopt.h>
 #include <libakrypt.h>

/* ----------------------------------------------------------------------------------------------- */
#ifdef LIBAKRYPT_HAVE_DIRENT_H
 #define __USE_MISC
 #include <dirent.h>
 #ifndef DT_DIR
  #define DT_DIR (4)
 #endif
 #ifndef DT_REG
  #define DT_REG (8)
 #endif
#else
 #include <msvc-dirent.h>
#endif
#ifdef LIBAKRYPT_HAVE_FNMATCH_H
 #include <fnmatch.h>
#endif
#ifdef LIBAKRYPT_HAVE_SYSSTAT_H
 #include <sys/stat.h>
#endif

#ifdef _WIN32
 #include <windows.h>
 #include <shlwapi.h>
#endif
/* ----------------------------------------------------------------------------------------------- */
 extern char audit_filename[1024];
 extern ak_function_log *audit;

/* ----------------------------------------------------------------------------------------------- */
/* функция вывода сообщений об ошибках в файл */
 int akrypt_audit_function( const char *message );
/* установка пользовательского файла для вывода аудита */
 void akrypt_set_audit( const char * );

/* ----------------------------------------------------------------------------------------------- */
/* проверка корректности заданной пользователем команды */
 ak_bool akrypt_check_command( const char *, char * );
/* вывод очень короткой справки о программе */
 int akrypt_litehelp( void );
/* вывод длинной справки о программе */
 int akrypt_help( void );

/* ----------------------------------------------------------------------------------------------- */
/* определение функции для выполнения действий с заданным файлом */
 typedef int ( ak_function_find_handle )( ak_handle , const char * );
/* обход каталога с учетом заданной маски */
 int akrypt_find( const char *, const char *, ak_function_find_handle *, ak_handle , ak_bool );
/* проверка, является ли заданная стирока файлом или директорией */
 int akrypt_file_or_directory( const char * );

/* ----------------------------------------------------------------------------------------------- */
/* реализации пользовательских команд */
 int akrypt_show( int argc, char *argv[] );
 int akrypt_hash( int argc, char *argv[] );

 #endif
/* ----------------------------------------------------------------------------------------------- */
/*                                                                                       akrypt.h  */
/* ----------------------------------------------------------------------------------------------- */

