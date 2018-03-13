#include <core/Godot.hpp>
#include <Reference.hpp>
#include <core/String.hpp>
#include <core/Array.hpp>

using namespace godot;

class Simple : public GodotScript<Reference> {
    GODOT_CLASS(Simple);
public:
    Simple() { }

    void say(String message) {
        Godot::print(message);
    }

    String hello(String target) {
        return String("Hello, {0}!").format(Array::make(target));
    }

    static void _register_methods() {
        register_method("say", &Simple::say);
        register_method("hello", &Simple::hello);
    }
};

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o)
{
    Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *o)
{
    Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void *handle)
{
    Godot::nativescript_init(handle);
    register_class<Simple>();
}
