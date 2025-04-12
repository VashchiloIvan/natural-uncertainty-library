.PHONY up:
up:
	swig -csharp -namespace NaturalUncertaintyCsharpApi -c++ -outdir ../natural-uncertainty-csharp-api/natural-uncertainty-csharp-api ./wrapper/csharp/natural-uncertainty-lib.i
	#/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake --build /Users/ivanvashchilo/Documents/DecisionPlatform/natural-uncertainty/cmake-build-debug --target natural_uncertainty -j 6
	cp -f ./cmake-build-debug/libnatural_uncertainty.dylib /usr/local/share/dotnet/shared/Microsoft.NETCore.App/7.0.5/libnatural_uncertainty.dylib