/* ----------------------------------------------------------------------------------------------- */
/*  Copyright (c) 2014 - 2018 by Axel Kenzo, axelkenzo@mail.ru                                     */
/*                                                                                                 */
/*  Файл ak_mac.h                                                                                  */
/*  - содержит описания функций, реализующих алгоритмы итерационного сжатия.                       */
/* ----------------------------------------------------------------------------------------------- */
#ifndef __AK_MAC_H__
#define __AK_MAC_H__

/* ----------------------------------------------------------------------------------------------- */
 #include <ak_hmac.h>
 #include <ak_omac.h>

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Структура предназначенная для итеративного вычисления значений сжимающих отображений.

    К таким отображениям могут быть как бесключевые функции хеширования, так и ключевые функции
    хеширования (функции выработки имитовставки).                                                  */
/* ----------------------------------------------------------------------------------------------- */
 typedef struct mac
{
 /*! \brief Тип криптографического механизма */
  oid_engines engine;
 /*! \brief указатель на контекст сжимающего преобразования */
  ak_pointer ctx;
 /*! \brief массив, предназначенный для временного хранения обрабатываемых данных */
  ak_uint8 *data;
 /*! \brief длина блока обрабатываемых данных */
  size_t bsize;
 /*! \brief длина хеш-кода (результата применения сжимающего отображения)  */
  size_t hsize;
 /*! \brief количество элементов, хранящихся в массиве data */
  size_t length;
 /*! \brief функция очистки контекста сжимающего преобразования */
  ak_function_mac_clean *clean;
 /*! \brief функция обработки данных, длина которых кратна длине обрабатываемого блока */
  ak_function_mac_update *update;
 /*! \brief функция завершения сжимающего преобразования */
  ak_function_mac_finalize *finalize;
 /*! \brief функция удаления контекста сжимающего преобразования */
  ak_function_free_object *free;

} *ak_mac;

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Инициализация контекста сжимающего отображения, реализуемого при помощи бесключевой
    функции хеширования. */
 int ak_mac_context_create_hash( ak_mac , ak_hash );
/*! \brief Инициализация контекста сжимающего отображения, реализуемого при помощи ключевой
    функции хеширования HMAC. */
 int ak_mac_context_create_hmac( ak_mac , ak_hmac );
/*! \brief Инициализация контекста сжимающего отображения, реализуемого при помощи
    функции выработки имитовставки (ключевой функции хеширования) ГОСТ Р 34.13-2015. */
 int ak_mac_context_create_omac( ak_mac , ak_omac );
/*! \brief Инициализация контекста сжимающего отображения с использованием идентификатора
    базового криптографического алгоритма. */
 int ak_mac_context_create_oid( ak_mac , ak_oid );
/*! \brief Уничтожение контекста сжимающего отображения. */
 int ak_mac_context_destroy( ak_mac );
/*! \brief Освобождение памяти из под контекста сжимающего отображения. */
 ak_pointer ak_mac_context_delete( ak_pointer );

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Присвоение контексту сжимающего отображения (секретному ключу) константного значения. */
 int ak_mac_context_set_key( ak_mac , const ak_pointer , const size_t , const ak_bool );

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Очистка контекста сжимающего отображения. */
 int ak_mac_context_clean( ak_mac );
/*! \brief Обновление состояния контекста сжимающего отображения. */
 int ak_mac_context_update( ak_mac , const ak_pointer , const size_t );
/*! \brief Обновление состояние и вычисление результата применения сжимающего отображения. */
 ak_buffer ak_mac_context_finalize( ak_mac , const ak_pointer , const size_t , ak_pointer );
/*! \brief Применение сжимающего отображения к заданной области памяти. */
 ak_buffer ak_mac_context_ptr( ak_mac , const ak_pointer , const size_t , ak_pointer );
/*! \brief Применение сжимающего отображения к заданному файлу. */
 ak_buffer ak_mac_context_file( ak_mac , const char* , ak_pointer );

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Проверка корректной работы механизмов итерационного сжатия для функций хеширования. */
 ak_bool ak_mac_test_hash_functions( void );
/*! \brief Проверка корректной работы механизмов итерационного сжатия для семейства ключевых
    функций хеширования HMAC. */
 ak_bool ak_mac_test_hmac_functions( void );
/*! \brief Проверка корректной работы алгоритма выработки имитовставки ГОСТ Р 34.13-2015. */
 ak_bool ak_mac_test_omac_functions( void );

#endif
/* ----------------------------------------------------------------------------------------------- */
/*                                                                                       ak_mac.h  */
/* ----------------------------------------------------------------------------------------------- */

