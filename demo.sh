#!/bin/bash

dfx start --background
dfx canister create shift-left
dfx build
dfx canister install shift-left
dfx canister call shift-left test
