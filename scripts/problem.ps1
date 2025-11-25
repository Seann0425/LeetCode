param (
    [Parameter(Mandatory=$true)]
    [string]$name
)

Set-Location -Path "C:\Users\Sean\code\LeetCode_cpp"
Copy-Item -Path "LeetCode_template.cpp" -Destination "$name.cpp"
Write-Host "Created file: $name.cpp"
code "$name.cpp"