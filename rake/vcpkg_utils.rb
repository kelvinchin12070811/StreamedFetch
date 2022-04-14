# frozen_string_literal: true

require_relative './config'
def bootstrap_vcpkg = system("#{CONFIG[:vcpkg_path]}/bootstrap-vcpkg")

def exec_vcpkg
  ARGV.shift
  system "#{CONFIG[:vcpkg_path]}/vcpkg #{ARGV.join(' ')}"
end
