# frozen_string_literal: true

require 'fileutils'

require_relative './config'

def gen_docs = system("#{CONFIG[:doxygen_path]} ./Doxyfile")

def clear_docs
  FileUtils.remove_dir('docs', true)
end

def get_docs_path
  puts "file:///#{Dir.pwd}/docs/html/index.html"
end
