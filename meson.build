project('Kings Duel', 'cpp', default_options: ['cpp_std=c++20'], version: '0.1.0')

sources = [
  'src/Game.cpp',
  'src/main.cpp'
  ]

sfml_dep = declare_dependency(
  include_directories : '/usr/include/SFML',
  link_args: [
      '-L/usr/lib/',
      '-lsfml-graphics',
      '-lsfml-window',
      '-lsfml-system'
  ]
)

executable('Kings Duel', sources, dependencies : sfml_dep)
