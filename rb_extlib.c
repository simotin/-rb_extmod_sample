#include <stdlib.h>
#include "ruby.h"

#define DAYS_YEAR   (365)       // 1年の日数

VALUE rb_cExtLib;

static VALUE rb_extlib_hello(VALUE self, VALUE name);

void Init_extlib( void ) {
    VALUE module;

    // モジュール定義
    module = rb_define_module( "ExtLib" );

    // モジュールにメソッドの登録する
    rb_define_module_function( module, "hello", rb_extlib_hello, 1 );

    // モジュールに定数を登録する
    rb_define_const( module, "DAYS_YEAR", INT2FIX( DAYS_YEAR ) );
    return;
}

static VALUE rb_extlib_hello(VALUE self, VALUE name)
{
    char *str = NULL;

    // 型チェック
    Check_Type( name, T_STRING );

    // Ruby の文字列は StringValuePtr でchar* として取り出せる
    str = StringValuePtr(name);
    printf("Hello %s!\n", str);
    return Qnil;
}
