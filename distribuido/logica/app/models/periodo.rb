class Periodo < ApplicationRecord
  has_many :horarios
  has_many :disponibilidad_salas
  has_many :disponibilidad_docentes
end
