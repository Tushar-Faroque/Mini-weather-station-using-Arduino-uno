from django.shortcuts import render
from django.http import HttpResponse
from .models import data1


def home(request):
    return render(request, 'home/home.html')

def about(request):
    return render(request, 'home/about.html')

def ac_room(request):
    return render(request, 'home/ac.html')

def kitchen(request):
    return render(request, 'home/kitchen.html')

def data1_view(request):
    # Create the HttpResponse object with the appropriate CSV header.
    obj = data1.objects.get(id=1)
    query_results = data1.objects.all()
    # context = {
    #     'ID': query_results.id,
    #     'Temp': query_results.Temp,
    #     'Humidity': query_results.Humidity,
    #     'Air_Quality': query_results.Air_Quality,
    #     'Water_Level': query_results.Water_Level

    # }
    context = {
        'object': query_results
    }
    return render(request, 'home/normal.html', context)
