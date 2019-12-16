from django.db import models

# Create your models here.
class data1(models.Model):
    Date_Time = models.CharField(max_length=120)
    Temp = models.IntegerField()
    Humidity = models.IntegerField()
    Air_Quality = models.IntegerField()
    Water_Level = models.IntegerField()
