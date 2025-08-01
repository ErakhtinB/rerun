// DO NOT EDIT! This file was auto-generated by crates/build/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/store/re_types/definitions/rerun/components/plane3d.fbs".

#pragma once

#include "../datatypes/plane3d.hpp"
#include "../result.hpp"

#include <cstdint>
#include <memory>

namespace rerun::components {
    /// **Component**: An infinite 3D plane represented by a unit normal vector and a distance.
    ///
    /// Any point P on the plane fulfills the equation `dot(xyz, P) - d = 0`,
    /// where `xyz` is the plane's normal and `d` the distance of the plane from the origin.
    /// This representation is also known as the Hesse normal form.
    ///
    /// Note: although the normal will be passed through to the
    /// datastore as provided, when used in the Viewer, planes will always be normalized.
    /// I.e. the plane with xyz = (2, 0, 0), d = 1 is equivalent to xyz = (1, 0, 0), d = 0.5
    struct Plane3D {
        rerun::datatypes::Plane3D xyzd;

      public:
        Plane3D() = default;

        Plane3D(rerun::datatypes::Plane3D xyzd_) : xyzd(xyzd_) {}

        Plane3D& operator=(rerun::datatypes::Plane3D xyzd_) {
            xyzd = xyzd_;
            return *this;
        }

        /// Cast to the underlying Plane3D datatype
        operator rerun::datatypes::Plane3D() const {
            return xyzd;
        }
    };
} // namespace rerun::components

namespace rerun {
    static_assert(sizeof(rerun::datatypes::Plane3D) == sizeof(components::Plane3D));

    /// \private
    template <>
    struct Loggable<components::Plane3D> {
        static constexpr std::string_view ComponentType = "rerun.components.Plane3D";

        /// Returns the arrow data type this type corresponds to.
        static const std::shared_ptr<arrow::DataType>& arrow_datatype() {
            return Loggable<rerun::datatypes::Plane3D>::arrow_datatype();
        }

        /// Serializes an array of `rerun::components::Plane3D` into an arrow array.
        static Result<std::shared_ptr<arrow::Array>> to_arrow(
            const components::Plane3D* instances, size_t num_instances
        ) {
            if (num_instances == 0) {
                return Loggable<rerun::datatypes::Plane3D>::to_arrow(nullptr, 0);
            } else if (instances == nullptr) {
                return rerun::Error(
                    ErrorCode::UnexpectedNullArgument,
                    "Passed array instances is null when num_elements> 0."
                );
            } else {
                return Loggable<rerun::datatypes::Plane3D>::to_arrow(
                    &instances->xyzd,
                    num_instances
                );
            }
        }
    };
} // namespace rerun
