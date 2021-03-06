#ifndef OSM_NODE_WRAP_HPP
#define OSM_NODE_WRAP_HPP

// v8/node
#include "include_v8.hpp"

// osmium
#include <osmium/osm/node.hpp>
namespace osmium {
    class OSMEntity;
}

// node-osmium
#include "node_osmium.hpp"
#include "osm_entity_wrap.hpp"
#include "osm_object_wrap.hpp"
#include "utils.hpp"

namespace node_osmium {

    class OSMNodeWrap : public OSMObjectWrap {

        static v8::Handle<v8::Value> get_type(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
            return symbol_node;
        }

        static v8::Handle<v8::Value> get_coordinates(v8::Local<v8::String> property, const v8::AccessorInfo& info);
        static v8::Handle<v8::Value> get_lon(v8::Local<v8::String> property, const v8::AccessorInfo& info);
        static v8::Handle<v8::Value> get_lat(v8::Local<v8::String> property, const v8::AccessorInfo& info);
        static v8::Handle<v8::Value> wkb(const v8::Arguments& args);
        static v8::Handle<v8::Value> wkt(const v8::Arguments& args);

    public:

        static v8::Persistent<v8::FunctionTemplate> constructor;
        static void Initialize(v8::Handle<v8::Object> target);
        static v8::Handle<v8::Value> New(const v8::Arguments& args);

        static const osmium::Node& wrapped(const v8::Local<v8::Object>& object) {
            return static_cast<const osmium::Node&>(unwrap<OSMEntityWrap>(object));
        }

        OSMNodeWrap() :
            OSMObjectWrap() {
        }

        OSMNodeWrap(const osmium::OSMEntity& entity) :
            OSMObjectWrap(entity) {
        }

    private:

        ~OSMNodeWrap() = default;

    }; // class OSMNodeWrap

} // namespace node_osmium

#endif // OSM_NODE_WRAP_HPP
