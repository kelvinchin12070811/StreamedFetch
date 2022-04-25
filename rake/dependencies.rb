# frozen_string_literal: true

require_relative './config'

def install_dependencies
  CONFIG[:dependencies].each_with_index do |dependency, index|
    puts "\n[#{index + 1}/#{CONFIG[:dependencies].length}] Installing #{dependency}..."
    exec "#{CONFIG[:vcpkg_path]}/vcpkg install #{dependency}"
  end
end

def list_dependencies
  puts 'Required vcpkg dependencies:'
  CONFIG[:dependencies].each do |dependency|
    puts " • #{dependency}"
  end
end
