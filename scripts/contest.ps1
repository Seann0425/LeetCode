param (
    [Parameter(Mandatory = $true)]
    [int]$X
)

Set-Location -Path "C:\Users\Sean\code\LeetCode_cpp"

for ($i = 0; $i -lt 4; $i++) {
    Copy-Item -Path "LeetCode_template.cpp" -Destination "$($X + $i).cpp"
    Write-Host "Created file: $($X + $i).cpp"
    # code-insiders "WIP\$($X + $i).cpp"
}