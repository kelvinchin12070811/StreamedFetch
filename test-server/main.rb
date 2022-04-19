#! /usr/bin/env ruby
# frozen_string_literal: true

require 'sinatra'

get '/' do
  puts request.env['HTTP_USER_AGENT']
  return [
    418,
    {
      'content-type' => 'application/json',
      'server' => '418 Teh Tarik Server'
    },
    '{"message": "I\'m a teapot"}'
  ]
end
