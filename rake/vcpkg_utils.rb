# frozen_string_literal: true

require_relative './config'
def bootstrap_vcpkg = exec("#{CONFIG[:vcpkg_path]}/bootstrap-vcpkg")

def exec_vcpkg
  ARGV.shift
  exec "#{CONFIG[:vcpkg_path]}/vcpkg #{ARGV.join(' ')}"
end
