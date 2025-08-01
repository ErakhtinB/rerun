// DO NOT EDIT! This file was auto-generated by crates/build/re_types_builder/src/codegen/rust/api.rs
// Based on "crates/store/re_types/definitions/rerun/datatypes/entity_path.fbs".

#![allow(unused_braces)]
#![allow(unused_imports)]
#![allow(unused_parens)]
#![allow(clippy::clone_on_copy)]
#![allow(clippy::cloned_instead_of_copied)]
#![allow(clippy::map_flatten)]
#![allow(clippy::needless_question_mark)]
#![allow(clippy::new_without_default)]
#![allow(clippy::redundant_closure)]
#![allow(clippy::too_many_arguments)]
#![allow(clippy::too_many_lines)]

use crate::try_serialize_field;
use crate::SerializationResult;
use crate::{ComponentBatch as _, SerializedComponentBatch};
use crate::{ComponentDescriptor, ComponentType};
use crate::{DeserializationError, DeserializationResult};

/// **Datatype**: A path to an entity in the `ChunkStore`.
#[derive(Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Default, Hash)]
#[repr(transparent)]
pub struct EntityPath(pub crate::ArrowString);

crate::macros::impl_into_cow!(EntityPath);

impl crate::Loggable for EntityPath {
    #[inline]
    fn arrow_datatype() -> arrow::datatypes::DataType {
        #![allow(clippy::wildcard_imports)]
        use arrow::datatypes::*;
        DataType::Utf8
    }

    fn to_arrow_opt<'a>(
        data: impl IntoIterator<Item = Option<impl Into<::std::borrow::Cow<'a, Self>>>>,
    ) -> SerializationResult<arrow::array::ArrayRef>
    where
        Self: Clone + 'a,
    {
        #![allow(clippy::wildcard_imports)]
        #![allow(clippy::manual_is_variant_and)]
        use crate::{arrow_helpers::as_array_ref, Loggable as _, ResultExt as _};
        use arrow::{array::*, buffer::*, datatypes::*};
        Ok({
            let (somes, data0): (Vec<_>, Vec<_>) = data
                .into_iter()
                .map(|datum| {
                    let datum: Option<::std::borrow::Cow<'a, Self>> = datum.map(Into::into);
                    let datum = datum.map(|datum| datum.into_owned().0);
                    (datum.is_some(), datum)
                })
                .unzip();
            let data0_validity: Option<arrow::buffer::NullBuffer> = {
                let any_nones = somes.iter().any(|some| !*some);
                any_nones.then(|| somes.into())
            };
            {
                let offsets = arrow::buffer::OffsetBuffer::<i32>::from_lengths(
                    data0
                        .iter()
                        .map(|opt| opt.as_ref().map(|datum| datum.len()).unwrap_or_default()),
                );

                #[allow(clippy::unwrap_used)]
                let capacity = offsets.last().copied().unwrap() as usize;
                let mut buffer_builder = arrow::array::builder::BufferBuilder::<u8>::new(capacity);
                for data in data0.iter().flatten() {
                    buffer_builder.append_slice(data.as_bytes());
                }
                let inner_data: arrow::buffer::Buffer = buffer_builder.finish();

                #[allow(unsafe_code, clippy::undocumented_unsafe_blocks)]
                as_array_ref(unsafe {
                    StringArray::new_unchecked(offsets, inner_data, data0_validity)
                })
            }
        })
    }

    fn from_arrow_opt(
        arrow_data: &dyn arrow::array::Array,
    ) -> DeserializationResult<Vec<Option<Self>>>
    where
        Self: Sized,
    {
        #![allow(clippy::wildcard_imports)]
        use crate::{arrow_zip_validity::ZipValidity, Loggable as _, ResultExt as _};
        use arrow::{array::*, buffer::*, datatypes::*};
        Ok({
            let arrow_data = arrow_data
                .as_any()
                .downcast_ref::<StringArray>()
                .ok_or_else(|| {
                    let expected = Self::arrow_datatype();
                    let actual = arrow_data.data_type().clone();
                    DeserializationError::datatype_mismatch(expected, actual)
                })
                .with_context("rerun.datatypes.EntityPath#path")?;
            let arrow_data_buf = arrow_data.values();
            let offsets = arrow_data.offsets();
            ZipValidity::new_with_validity(offsets.windows(2), arrow_data.nulls())
                .map(|elem| {
                    elem.map(|window| {
                        let start = window[0] as usize;
                        let end = window[1] as usize;
                        let len = end - start;
                        if arrow_data_buf.len() < end {
                            return Err(DeserializationError::offset_slice_oob(
                                (start, end),
                                arrow_data_buf.len(),
                            ));
                        }

                        #[allow(unsafe_code, clippy::undocumented_unsafe_blocks)]
                        let data = arrow_data_buf.slice_with_length(start, len);
                        Ok(data)
                    })
                    .transpose()
                })
                .map(|res_or_opt| {
                    res_or_opt.map(|res_or_opt| res_or_opt.map(|v| crate::ArrowString::from(v)))
                })
                .collect::<DeserializationResult<Vec<Option<_>>>>()
                .with_context("rerun.datatypes.EntityPath#path")?
                .into_iter()
        }
        .map(|v| v.ok_or_else(DeserializationError::missing_data))
        .map(|res| res.map(|v| Some(Self(v))))
        .collect::<DeserializationResult<Vec<Option<_>>>>()
        .with_context("rerun.datatypes.EntityPath#path")
        .with_context("rerun.datatypes.EntityPath")?)
    }
}

impl From<crate::ArrowString> for EntityPath {
    #[inline]
    fn from(path: crate::ArrowString) -> Self {
        Self(path)
    }
}

impl From<EntityPath> for crate::ArrowString {
    #[inline]
    fn from(value: EntityPath) -> Self {
        value.0
    }
}

impl ::re_byte_size::SizeBytes for EntityPath {
    #[inline]
    fn heap_size_bytes(&self) -> u64 {
        self.0.heap_size_bytes()
    }

    #[inline]
    fn is_pod() -> bool {
        <crate::ArrowString>::is_pod()
    }
}
