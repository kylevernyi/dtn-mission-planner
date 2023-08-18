# Meson build file for dtnmp
project('dtn-mission-planner', 'cpp',
    version: '0.0.1',
    license: 'MIT',
    default_options: 'opengl=enabled'
)

cpp = meson.get_compiler('cpp')

## imgui core (enable all backends via options)
imgui_include_dirs = include_directories('.', 'external/imgui/backends', 'external/imgui', 'external/imnodes')
# these are the core imgui files that create the imgui library
imgui_sources = [
    'external/imgui/imgui_demo.cpp', 
    'external/imgui/imgui_draw.cpp', 
    'external/imgui/imgui_tables.cpp', 
    'external/imgui/imgui_widgets.cpp', 
    'external/imgui/imgui.cpp',
    'external/imnodes/imnodes.cpp']

imgui_dependencies = []

# renderer backends
if get_option('dx9').enabled()
    dx9_dep = cpp.find_library('d3d9', required: get_option('dx9'))
    if dx9_dep.found()
        imgui_sources += 'backends/imgui_impl_dx9.cpp'
        imgui_dependencies += dx9_dep
    endif
endif
if get_option('dx10').enabled()
    dx10_dep = cpp.find_library('d3d10', required: get_option('dx10'))
    if dx10_dep.found()
        imgui_sources += 'external/imgui/backends/imgui_impl_dx10.cpp'
        imgui_dependencies += dx10_dep
    endif
endif
if get_option('dx11').enabled()
    dx11_dep = cpp.find_library('d3d11', required: get_option('dx11'))
    if dx11_dep.found()
        imgui_sources += 'external/imgui/backends/imgui_impl_dx11.cpp'
        imgui_dependencies += dx11_dep
    endif
endif

if get_option('dx12').enabled()
    dx12_dep = cpp.find_library('d3d12', required: get_option('dx12'))
    if dx12_dep.found()
        imgui_sources += 'external/imgui/backends/imgui_impl_dx12.cpp'
        imgui_dependencies += dx12_dep
    endif
endif

if get_option('metal').enabled()
    metal_dep = cpp.find_library('metal', required: get_option('metal'))
    if get_option('metal').enabled()
        imgui_sources += 'external/imgui/backends/imgui_impl_metal.mm'
        imgui_dependencies += metal_dep
    endif
endif

if get_option('opengl').enabled()
    opengl_dep = dependency('gl', required: true)
    if get_option('opengl').enabled()
        imgui_sources += 'external/imgui/backends/imgui_impl_opengl3.cpp'
        imgui_dependencies += opengl_dep
    endif
endif

if get_option('vulkan').enabled()
    vulkan_dep = dependency('vulkan', required: get_option('vulkan'))
    if vulkan_dep.found()
        imgui_sources += 'external/imgui/backends/imgui_impl_vulkan.cpp'
        imgui_dependencies += vulkan_dep
    endif
endif

# platform backends
if get_option('glfw').enabled()
    glfw_dep = dependency('glfw3', required: get_option('glfw'))
    if glfw_dep.found()
        imgui_sources += 'external/imgui/backends/imgui_impl_glfw.cpp'
        imgui_dependencies += glfw_dep
    endif
endif

if get_option('sdl2').enabled()
    sdl2_dep = dependency('sdl2', required: get_option('sdl2'))
    if sdl2_dep.found()
        imgui_sources += 'external/imgui/backends/imgui_impl_sdl.cpp'
        imgui_dependencies += sdl2_dep
    endif
endif
if get_option('osx').enabled() or (get_option('osx').auto() and target_machine.system() == 'darwin')
    imgui_sources += 'external/imgui/backends/imgui_impl_osx.mm'
endif
if get_option('win').enabled() or (get_option('win').auto() and target_machine.system() == 'windows')
    imgui_sources += 'external/imgui/backends/imgui_impl_win32.cpp'
endif

# frameworks

if get_option('allegro5').enabled()
    allegro5_dep = dependency('allegro5', required: get_option('allegro5'))
    if allegro5_dep.found()
        imgui_sources += 'external/imgui/backends/imgui_impl_allegro5.cpp'
        imgui_dependencies += allegro5_dep
    endif
endif

if get_option('marmalade').enabled()
    marmalade_dep = cpp.find_library('marmalade', required: get_option('marmalade'))
    if marmalade_dep.found()
        imgui_sources += 'external/imgui/backends/imgui_impl_marmalade.cpp'
        imgui_dependencies += marmalade_dep
    endif
endif


imgui_library = static_library('imgui',
    [imgui_sources],
    dependencies: imgui_dependencies,
    include_directories: [imgui_include_dirs],
)
imgui_dep = declare_dependency(include_directories: imgui_include_dirs, link_with: imgui_library)


# Boost
boost_dep = dependency('boost', modules : ['filesystem'])

# dtnmp executable definition
dtnmp_sources = ['src/main.cpp',
    'src/DtnMp.cpp',
    'src/DtnMpApp.cpp']
dtnmp_include_drs = ['include']

executable('dtnmp', dtnmp_sources, dependencies : [imgui_dep, boost_dep], include_directories : [dtnmp_include_drs, imgui_include_dirs])