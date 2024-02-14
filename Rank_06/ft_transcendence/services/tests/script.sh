#!/bin/sh

apt-get update -y && apt-get upgrade -y

apt-get install nginx -y

nginx -g "daemon off;"