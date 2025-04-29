# Use the .NET SDK image for building the app (with .NET 8.0)
FROM mcr.microsoft.com/dotnet/sdk:8.0 AS build
WORKDIR /src

# Copy the project file and restore any dependencies (via 'dotnet restore')
COPY ["CalculatorApp/CalculatorApp.csproj", "CalculatorApp/"]
RUN dotnet restore "CalculatorApp/CalculatorApp.csproj"

# Copy the rest of the application code
COPY . .

# Publish the application to the /app folder
RUN dotnet publish "CalculatorApp/CalculatorApp.csproj" -c Release -o /app/publish

# Define the final stage to run the application
FROM mcr.microsoft.com/dotnet/aspnet:8.0 AS base
WORKDIR /app
COPY --from=build /app/publish .

# Start the app
ENTRYPOINT ["dotnet", "CalculatorApp.dll"]
